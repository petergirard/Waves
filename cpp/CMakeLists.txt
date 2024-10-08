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

        src/Model/Mission/MissionExecutionState.h
        src/Model/Mission/Mission.h
        src/Model/Mission/Waypoint.h
        src/Model/Maneuver/ManeuverGoalsState.h

        src/Model/Maneuver/ManeuverControlsState.h
        src/Model/Navigation/PhysicalState.h

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

        # Pilot
        src/Pilot/Maneuver/PidController.cpp
        src/Pilot/Maneuver/PidController.h
        src/Pilot/Maneuver/DriveSettings.h
        src/Pilot/Maneuver/PidOutput.h
        src/Pilot/Maneuver/PidSettings.h

        src/Pilot/Mission/MissionEngine.cpp
        src/Pilot/Mission/MissionEngine.h

        src/Pilot/Pilot.cpp
        src/Pilot/Pilot.h
        src/Comms/Json/JsonSerialization.cpp
        src/Comms/Json/JsonSerialization.h
        src/Comms/RabbitMQ/RabbitClient.cpp
        src/Comms/RabbitMQ/RabbitClient.h
        src/Comms/RabbitMQ/RabbitPublisher.h
        src/Comms/RabbitMQ/RabbitSubscriber.h
        src/Model/Report/WavesStatusReport.h
        src/Sim/SimplePhysics.cpp
        src/Sim/SimplePhysics.h
        src/Log/DataLogger.cpp
        src/Log/DataLogger.h
        src/Util/FormatUtils.h
        src/Log/LogHeaderIndex.h
        src/Pilot/Mission/MissionRepo.cpp
        src/Pilot/Mission/MissionRepo.h
        src/Model/Command/LoadMissionCommand.h
        src/Model/Command/RunMissionCommand.h
        src/Model/Command/StopCommand.h
        src/Pilot/Fuel/BatteryManager.cpp
        src/Pilot/Fuel/BatteryManager.h
        src/Model/Misc/BatteryState.h
        src/Control/CommandManager.cpp
        src/Control/CommandManager.h
        src/Comms/IConnectable.h
        src/Control/CommandProcessor.h
        src/Util/Thread/ConcurrentQueue.h
        src/Control/CommandProcessorBase.h
        src/Pilot/Maneuver/ManeuverEngine.cpp
        src/Pilot/Maneuver/ManeuverEngine.h
        src/Model/Maneuver/DriveToManeuver.h
        src/Model/Maneuver/ManeuverCompletionCriteria.h
        src/Model/Maneuver/PrimitiveManeuver.h
        src/Model/Maneuver/ParkManeuver.h
        src/Model/Maneuver/ManeuverBase.h
        src/Pilot/Maneuver/ManeuverWrapper.h
        src/Model/Command/ManeuverCommand.h
        src/Model/Command/CommandBase.h
        src/Control/CommandManager.cpp
)

# Link libraries
target_link_libraries(Waves
        ${RABBITMQ_LIBRARIES}
        SimpleAmqpClient
        nlohmann_json::nlohmann_json)