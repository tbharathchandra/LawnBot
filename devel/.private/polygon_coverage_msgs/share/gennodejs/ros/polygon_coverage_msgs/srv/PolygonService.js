// Auto-generated. Do not edit!

// (in-package polygon_coverage_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let PolygonWithHolesStamped = require('../msg/PolygonWithHolesStamped.js');

//-----------------------------------------------------------


//-----------------------------------------------------------

class PolygonServiceRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.polygon = null;
    }
    else {
      if (initObj.hasOwnProperty('polygon')) {
        this.polygon = initObj.polygon
      }
      else {
        this.polygon = new PolygonWithHolesStamped();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PolygonServiceRequest
    // Serialize message field [polygon]
    bufferOffset = PolygonWithHolesStamped.serialize(obj.polygon, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PolygonServiceRequest
    let len;
    let data = new PolygonServiceRequest(null);
    // Deserialize message field [polygon]
    data.polygon = PolygonWithHolesStamped.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += PolygonWithHolesStamped.getMessageSize(object.polygon);
    return length;
  }

  static datatype() {
    // Returns string type for a service object
    return 'polygon_coverage_msgs/PolygonServiceRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'ded2f55b70e30d5b47a2955e617ba1a7';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # A service to set a new polygon with holes.
    # Request fields:
    polygon_coverage_msgs/PolygonWithHolesStamped polygon # The new polygon.
    
    ================================================================================
    MSG: polygon_coverage_msgs/PolygonWithHolesStamped
    # A stamped polygon with holes.
    std_msgs/Header header
    polygon_coverage_msgs/PolygonWithHoles polygon
    
    ================================================================================
    MSG: std_msgs/Header
    # Standard metadata for higher-level stamped data types.
    # This is generally used to communicate timestamped data 
    # in a particular coordinate frame.
    # 
    # sequence ID: consecutively increasing ID 
    uint32 seq
    #Two-integer timestamp that is expressed as:
    # * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
    # * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
    # time-handling sugar is provided by the client library
    time stamp
    #Frame this data is associated with
    string frame_id
    
    ================================================================================
    MSG: polygon_coverage_msgs/PolygonWithHoles
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
    const resolved = new PolygonServiceRequest(null);
    if (msg.polygon !== undefined) {
      resolved.polygon = PolygonWithHolesStamped.Resolve(msg.polygon)
    }
    else {
      resolved.polygon = new PolygonWithHolesStamped()
    }

    return resolved;
    }
};

class PolygonServiceResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PolygonServiceResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PolygonServiceResponse
    let len;
    let data = new PolygonServiceResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 1;
  }

  static datatype() {
    // Returns string type for a service object
    return 'polygon_coverage_msgs/PolygonServiceResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '358e233cde0c8a8bcfea4ce193f8fc15';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Response fields:
    bool success # True on success, false on polygon error.
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PolygonServiceResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    return resolved;
    }
};

module.exports = {
  Request: PolygonServiceRequest,
  Response: PolygonServiceResponse,
  md5sum() { return '7c41cb26384cf37ba066f9b416bd9391'; },
  datatype() { return 'polygon_coverage_msgs/PolygonService'; }
};
