from dataclasses import dataclass, field

from model.base.orientation import Orientation
from model.base.point3D import Point3D
from model.base.vector3D import Vector3D


@dataclass
class PhysicalState:
    position: Point3D = field(default_factory=Point3D)
    velocityWorldFrame: Vector3D = field(default_factory=Vector3D)
    accelerationWorldFrame: Vector3D = field(default_factory=Vector3D)
    velocityVehicleFrame: Vector3D = field(default_factory=Vector3D)
    accelerationVehicleFrame: Vector3D = field(default_factory=Vector3D)
    attitude: Orientation = field(default_factory=Orientation)
    attitudeVelocity: Orientation = field(default_factory=Orientation)
    attitudeAcceleration: Orientation = field(default_factory=Orientation)

    def to_dict(self):
        return {
            'position': self.position.to_dict(),
            'velocityWorldFrame': self.velocityWorldFrame.to_dict(),
            'accelerationWorldFrame': self.accelerationWorldFrame.to_dict(),
            'velocityVehicleFrame': self.velocityVehicleFrame.to_dict(),
            'accelerationVehicleFrame': self.accelerationVehicleFrame.to_dict(),
            'attitude': self.attitude.to_dict(),
            'attitudeVelocity': self.attitudeVelocity.to_dict(),
            'attitudeAcceleration': self.attitudeAcceleration.to_dict(),
        }

    @staticmethod
    def from_dict(data):
        return PhysicalState(
            position=Point3D.from_dict(data['position']),
            velocityWorldFrame=Vector3D.from_dict(data['velocityWorldFrame']),
            accelerationWorldFrame=Vector3D.from_dict(data['accelerationWorldFrame']),
            velocityVehicleFrame=Vector3D.from_dict(data['velocityVehicleFrame']),
            accelerationVehicleFrame=Vector3D.from_dict(data['accelerationVehicleFrame']),
            attitude=Orientation.from_dict(data['attitude']),
            attitudeVelocity=Orientation.from_dict(data['attitudeVelocity']),
            attitudeAcceleration=Orientation.from_dict(data['attitudeAcceleration']),
        )