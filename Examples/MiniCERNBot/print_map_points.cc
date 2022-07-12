/**
* This file is part of ORB-SLAM3
*
* Copyright (C) 2017-2021 Carlos Campos, Richard Elvira, Juan J. Gómez Rodríguez, José M.M. Montiel and Juan D. Tardós, University of Zaragoza.
* Copyright (C) 2014-2016 Raúl Mur-Artal, José M.M. Montiel and Juan D. Tardós, University of Zaragoza.
*
* ORB-SLAM3 is free software: you can redistribute it and/or modify it under the terms of the GNU General Public
* License as published by the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* ORB-SLAM3 is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
* the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License along with ORB-SLAM3.
* If not, see <http://www.gnu.org/licenses/>.
*/

#include <signal.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <ctime>
#include <sstream>

#include <condition_variable>

#include <opencv2/core/core.hpp>

#include <librealsense2/rs.hpp>
#include "librealsense2/rsutil.h"


#include <System.h>

using namespace std;



int main(int argc, char **argv) {

    if (argc < 3 || argc > 4) {
        cerr << endl
             << "Usage: ./print_map_points path_to_vocabulary path_to_settings (trajectory_file_name)"
             << endl;
        return 1;
    }
    
    string file_name;
    bool bFileName = false;

    if (argc == 4) {
        file_name = string(argv[argc - 1]);
        bFileName = true;
    }
    
    ORB_SLAM3::System tempSLAM(argv[1], argv[2], ORB_SLAM3::System::RGBD, false, 0, file_name);
    ORB_SLAM3::Atlas* mpAtlas = tempSLAM.GetAtlas();
    std::vector<ORB_SLAM3::Map*> allMaps = mpAtlas->GetAllMaps();
    
    std::cout << "# number of maps = " << allMaps.size() << std::endl;
    std::vector<ORB_SLAM3::MapPoint*> allMap0Points = allMaps[0]->GetAllMapPoints();
    std::cout << "# map 0 size=" << allMap0Points.size() << std::endl;
    
    for (auto p : allMap0Points) {
	    Eigen::Vector3f v = p->GetWorldPos();
	    std::cout << v.x() << "," << v.y() << "," << v.z() << std::endl;
    }
    
    return 0;
}
