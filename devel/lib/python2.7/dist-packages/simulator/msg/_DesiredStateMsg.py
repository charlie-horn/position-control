# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from simulator/DesiredStateMsg.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class DesiredStateMsg(genpy.Message):
  _md5sum = "cc61550db4d69f891417c4905802aea9"
  _type = "simulator/DesiredStateMsg"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """# MotorCommands
#
# Rikky Duivenvoorden 2017-01-30 -- For use in AER1217 Winter 2017
#
# Data communicates the motor commands in RPM as a four element array in the
# following order [front_left, front_right, rear_left, rear_right]

float64[3] x
float64[3] x_dot
float64 yaw
float64 yaw_rate
"""
  __slots__ = ['x','x_dot','yaw','yaw_rate']
  _slot_types = ['float64[3]','float64[3]','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       x,x_dot,yaw,yaw_rate

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(DesiredStateMsg, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.x is None:
        self.x = [0.] * 3
      if self.x_dot is None:
        self.x_dot = [0.] * 3
      if self.yaw is None:
        self.yaw = 0.
      if self.yaw_rate is None:
        self.yaw_rate = 0.
    else:
      self.x = [0.] * 3
      self.x_dot = [0.] * 3
      self.yaw = 0.
      self.yaw_rate = 0.

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      buff.write(_get_struct_3d().pack(*self.x))
      buff.write(_get_struct_3d().pack(*self.x_dot))
      _x = self
      buff.write(_get_struct_2d().pack(_x.yaw, _x.yaw_rate))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 24
      self.x = _get_struct_3d().unpack(str[start:end])
      start = end
      end += 24
      self.x_dot = _get_struct_3d().unpack(str[start:end])
      _x = self
      start = end
      end += 16
      (_x.yaw, _x.yaw_rate,) = _get_struct_2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      buff.write(self.x.tostring())
      buff.write(self.x_dot.tostring())
      _x = self
      buff.write(_get_struct_2d().pack(_x.yaw, _x.yaw_rate))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      end = 0
      start = end
      end += 24
      self.x = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=3)
      start = end
      end += 24
      self.x_dot = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=3)
      _x = self
      start = end
      end += 16
      (_x.yaw, _x.yaw_rate,) = _get_struct_2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2d = None
def _get_struct_2d():
    global _struct_2d
    if _struct_2d is None:
        _struct_2d = struct.Struct("<2d")
    return _struct_2d
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
