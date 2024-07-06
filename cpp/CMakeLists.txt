cmake_minimum_required(VERSION 3.28)
project(Waves)

set(CMAKE_CXX_STANDARD 23)

# Find and include RabbitMQ C client library
find_package(PkgConfig REQUIRED)
pkg_check_modules(RABBITMQ REQUIRED librabbitmq)

# Find nlohmann_json library
find_package(nlohmann_json 3.10.5 REQUIRED)

# Include SimpleAmqpClient
include_directories(/home/peter/dev/SimpleAmqpClient)
link_directories(/home/peter/dev/SimpleAmqpClient/build)

add_executable(Waves main.cpp

        # Model
        src/Model/Base/Orientation.h
        src/Model/Base/Point3D.h
        src/Model/Base/Vector3D.h
        src/Model/Base/Vector2D.h
        src/Model/Base/Point2D.h
        src/Model/Base/TimePoint.h

        src/Model/Mission/MissionState.h
        src/Model/Mission/Mission.h
        src/Model/Mission/Waypoint.h
        src/Model/Maneuver/ManeuverGoalsState.h

        src/Model/Maneuver/ManeuverControlsState.h
        src/Model/Maneuver/PhysicalState.h

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
        src/Comms/JsonSerialization.cpp
        src/Comms/JsonSerialization.h
        src/Comms/RabbitMQ/RabbitClient.cpp
        src/Comms/RabbitMQ/RabbitClient.h
        src/Comms/RabbitMQ/RabbitPublisher.cpp
        src/Comms/RabbitMQ/RabbitPublisher.h
        src/Comms/RabbitMQ/RabbitSubscriber.cpp
        src/Comms/RabbitMQ/RabbitSubscriber.h
        src/Comms/WavesStatusMessage.h
        src/Sim/SimplePhysics.cpp
        src/Sim/SimplePhysics.h
        src/Log/DataLogger.cpp
        src/Log/DataLogger.h
        src/Util/FormatUtils.h
        src/Log/LogHeaderIndex.h
)

# Link libraries
target_link_libraries(Waves
        ${RABBITMQ_LIBRARIES}
        SimpleAmqpClient
        nlohmann_json::nlohmann_json)