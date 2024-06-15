cmake_minimum_required(VERSION 3.28)
project(Waves)

set(CMAKE_CXX_STANDARD 23)

add_executable(Waves main.cpp

        # Model
        src/Model/Base/Orientation.h
        src/Model/Base/Point3D.h
        src/Model/Base/Vector3D.h
        src/Model/Base/Vector2D.h
        src/Model/Base/Point2D.h
        src/Model/Base/TimePoint.h

        src/Model/Mission/MissionStatus.h
        src/Model/Mission/Mission.h
        src/Model/Mission/Waypoint.h
        src/Model/Mission/NavigationStatus.h

        src/Model/Maneuver/ManeuverControls.h
        src/Model/Maneuver/ManeuverState.h

        # Sim
        src/Sim/Physics.cpp
        src/Sim/Physics.h
        src/Sim/Display.cpp
        src/Sim/Display.h

        # Util
        src/Util/UnitConversion.cpp
        src/Util/UnitConversion.h
        src/Util/MathUtils.cpp
        src/Util/MathUtils.h
        src/Util/FrameTransformations.cpp
        src/Util/FrameTransformations.h
        src/Util/GenericUtils.h

        # Vehicle
        src/Vehicle/Maneuver/ManeuverController.cpp
        src/Vehicle/Maneuver/ManeuverController.h
        src/Vehicle/Maneuver/ManeuverSettings.h
        src/Vehicle/Maneuver/Pid/PidCalculator.cpp
        src/Vehicle/Maneuver/Pid/PidCalculator.h
        src/Vehicle/Maneuver/Pid/PidOutput.h
        src/Vehicle/Maneuver/Pid/PidSettings.h

        src/Vehicle/Mission/MissionController.cpp
        src/Vehicle/Mission/MissionController.h

        src/Vehicle/VehicleMain.cpp
        src/Vehicle/VehicleMain.h
)
