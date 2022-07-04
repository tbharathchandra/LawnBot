// Auto-generated. Do not edit!

// (in-package polygon_coverage_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class PolygonWithHoles {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.hull = null;
      this.holes = null;
    }
    else {
      if (initObj.hasOwnProperty('hull')) {
        this.hull = initObj.hull
      }
      else {
        this.hull = new geometry_msgs.msg.Polygon();
      }
      if (initObj.hasOwnProperty('holes')) {
        this.holes = initObj.holes
      }
      else {
        this.holes = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PolygonWithHoles
    // Serialize message field [hull]
    bufferOffset = geometry_msgs.msg.Polygon.serialize(obj.hull, buffer, bufferOffset);
    // Serialize message field [holes]
    // Serialize the length for message field [holes]
    bufferOffset = _serializer.uint32(obj.holes.length, buffer, bufferOffset);
    obj.holes.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Polygon.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PolygonWithHoles
    let len;
    let data = new PolygonWithHoles(null);
    // Deserialize message field [hull]
    data.hull = geometry_msgs.msg.Polygon.deserialize(buffer, bufferOffset);
    // Deserialize message field [holes]
    // Deserialize array length for message field [holes]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.holes = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.holes[i] = geometry_msgs.msg.Polygon.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += geometry_msgs.msg.Polygon.getMessageSize(object.hull);
    object.holes.forEach((val) => {
      length += geometry_msgs.msg.Polygon.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'polygon_coverage_msgs/PolygonWithHoles';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '172a5c8423a33d0cd317c84e16aead83';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # A message to define a polygon with holes.
    geometry_msgs/Polygon hull
    geometry_msgs/Polygon[] holes
    
    ================================================================================
    MSG: geometry_msgs/Polygon
    #A specification of a polygon where the first and last points are assumed to be connected
    Point32[] points
    
    ================================================================================
    MSG: geometry_msgs/Point32
    # This contains the position of a point in free space(with 32 bits of precision).
    # It is recommeded to use Point wherever possible instead of Point32.  
    # 
    # This recommendation is to promote interoperability.  
    #
    # This message is designed to take up less space when sending
    # lots of points at once, as in the case of a PointCloud.  
    
    float32 x
    float32 y
    float32 z
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PolygonWithHoles(null);
    if (msg.hull !== undefined) {
      resolved.hull = geometry_msgs.msg.Polygon.Resolve(msg.hull)
    }
    else {
      resolved.hull = new geometry_msgs.msg.Polygon()
    }

    if (msg.holes !== undefined) {
      resolved.holes = new Array(msg.holes.length);
      for (let i = 0; i < resolved.holes.length; ++i) {
        resolved.holes[i] = geometry_msgs.msg.Polygon.Resolve(msg.holes[i]);
      }
    }
    else {
      resolved.holes = []
    }

    return resolved;
    }
};

module.exports = PolygonWithHoles;
