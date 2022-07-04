# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "rviz_polygon_tool;roscpp;nav_msgs;geometry_msgs;trajectory_msgs;visualization_msgs;std_srvs;eigen_conversions;polygon_coverage_msgs;polygon_coverage_geometry;polygon_coverage_planners;cgal_catkin".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-lpolygon_coverage_ros".split(';') if "-lpolygon_coverage_ros" != "" else []
PROJECT_NAME = "polygon_coverage_ros"
PROJECT_SPACE_DIR = "/home/bharath/catkin_ws/install"
PROJECT_VERSION = "0.0.0"
