cmake_minimum_required(VERSION 3.1)
project(xthreejs)

message(STATUS "Forcing tests build type to Release")
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)

set(XTHREEJS_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(XTHREEJS_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Configuration
# =============

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

set(XTHREEJS_INSTALL_LIBRARY_DIR "\"${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}\"")

configure_file (
    "${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs_config.hpp.in"
    "${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs_config.hpp"
)

# Versionning
# ===========

file(STRINGS "${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs_config.hpp" xthreejs_version_defines
     REGEX "#define XTHREEJS_VERSION_(MAJOR|MINOR|PATCH)")
foreach(ver ${xthreejs_version_defines})
    if(ver MATCHES "#define XTHREEJS_VERSION_(MAJOR|MINOR|PATCH) +([^ ]+)$")
        set(XTHREEJS_VERSION_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
    endif()
endforeach()
set(XTHREEJS_VERSION
    ${XTHREEJS_VERSION_MAJOR}.${XTHREEJS_VERSION_MINOR}.${XTHREEJS_VERSION_PATCH})
message(STATUS "xthreejs version: v${XTHREEJS_VERSION}")

# Binary version
# See the following URL for explanations about the binary versionning
# https://www.gnu.org/software/libtool/manual/html_node/Updating-version-info.html#Updating-version-info
file(STRINGS "${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs_config.hpp" xthreejs_version_defines
    REGEX "#define XTHREEJS_BINARY_(CURRENT|REVISION|AGE)")
foreach(ver ${xthreejs_version_defines})
    if(ver MATCHES "#define XTHREEJS_BINARY_(CURRENT|REVISION|AGE) +([^ ]+)$")
        set(XTHREEJS_BINARY_${CMAKE_MATCH_1} "${CMAKE_MATCH_2}" CACHE INTERNAL "")
    endif()
endforeach()
set(XTHREEJS_BINARY_VERSION
    ${XTHREEJS_BINARY_CURRENT}.${XTHREEJS_BINARY_REVISION}.${XTHREEJS_BINARY_AGE})
message(STATUS "xthreejs binary version: v${XTHREEJS_BINARY_VERSION}")

# Dependencies
# ============

find_package(cppzmq 4.2.3 REQUIRED)
find_package(xtl 0.4 REQUIRED)
find_package(xeus 0.10.1 REQUIRED)
find_package(xwidgets 0.7 REQUIRED)
find_package(xproperty 0.7 REQUIRED)

# Source files
# ============

set(XTHREEJS_HEADERS
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/tracks/xboolean_keyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/tracks/xcolor_keyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/tracks/xnumber_keyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/tracks/xquaternion_keyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/tracks/xstring_keyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/tracks/xvector_keyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xanimation_action.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xanimation_action_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xanimation_clip_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xanimation_mixer_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xanimation_object_group_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xanimation_utils_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xkeyframe_track_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xproperty_binding_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/animation/xproperty_mixer_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/audio/xaudio_analyser_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/audio/xaudio_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/audio/xaudio_listener_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/audio/xpositional_audio_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/base/xenums.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/base/xrender.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/base/xthree.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/base/xthree_types.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xarray_camera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xcamera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xcombined_camera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xcube_camera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xorthographic_camera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xperspective_camera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/cameras/xstereo_camera_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/controls/xcontrols_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/controls/xfly_controls_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/controls/xorbit_controls_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/controls/xpicker_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/controls/xtrackball_controls_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xbase_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xbase_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xbuffer_attribute_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xbuffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xclock_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xdirect_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xevent_dispatcher_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xgeometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xinstanced_buffer_attribute_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xinstanced_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xinstanced_interleaved_buffer_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xinterleaved_buffer_attribute_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xinterleaved_buffer_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xlayers_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xobject3d.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xobject3d_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xraycaster_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xrenderer.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/core/xuniform_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/core/xcurve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/core/xcurve_path_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/core/xfont_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/core/xpath_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/core/xshape_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/core/xshape_path_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xarc_curve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xcatmull_rom_curve3_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xcubic_bezier_curve3_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xcubic_bezier_curve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xellipse_curve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xline_curve3_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xline_curve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xquadratic_bezier_curve3_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xquadratic_bezier_curve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/curves/xspline_curve_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/objects/ximmediate_render_object_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/xscene_utils_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/extras/xshape_utils_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xbox_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xbox_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xcircle_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xcircle_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xcone_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xcylinder_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xcylinder_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xdodecahedron_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xedges_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xextrude_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xicosahedron_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xlathe_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xlathe_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xoctahedron_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xparametric_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xplane_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xplane_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xpolyhedron_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xring_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xring_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xshape_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xsphere_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xsphere_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtetrahedron_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtext_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtorus_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtorus_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtorus_knot_buffer_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtorus_knot_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xtube_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/geometries/xwireframe_geometry_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xarrow_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xaxes_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xbox3helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xbox_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xcamera_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xdirectional_light_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xface_normals_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xgrid_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xhemisphere_light_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xplane_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xpoint_light_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xpolar_grid_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xrect_area_light_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xskeleton_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xspot_light_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/helpers/xvertex_normals_helper_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xambient_light_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xdirectional_light_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xdirectional_light_shadow_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xhemisphere_light_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xlight_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xlight_shadow_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xpoint_light_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xrect_area_light_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xspot_light_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/lights/xspot_light_shadow_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xanimation_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xaudio_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xbuffer_geometry_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xcache_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xcompressed_texture_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xcube_texture_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xdata_texture_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xfile_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xfont_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/ximage_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xj_s_o_n_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xloader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xloading_manager_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xmaterial_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xobject_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/loaders/xtexture_loader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xline_basic_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xline_dashed_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmaterial.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmaterial_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_basic_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_depth_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_lambert_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_normal_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_phong_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_physical_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_standard_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xmesh_toon_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xpoints_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xraw_shader_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xshader_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xshadow_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/materials/xsprite_material_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/interpolants/xcubic_interpolant_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/interpolants/xdiscrete_interpolant_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/interpolants/xlinear_interpolant_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/interpolants/xquaternion_linear_interpolant_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xbox2_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xbox3_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xcylindrical_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xfrustum_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xinterpolant_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xline3_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xmath_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xplane.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xplane_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xquaternion_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xray_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xsphere_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xspherical_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/math/xtriangle_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xblackbox_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xbone_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xclone_array_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xgroup_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xl_o_d_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xlens_flare_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xline_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xline_loop_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xline_segments_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xmesh_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xpoints_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xskeleton_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xskinned_mesh_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/objects/xsprite_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/shaders/xuniform_lib.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_buffer_renderer_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_capabilities_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_extensions_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_geometries_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_indexed_buffer_renderer_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_lights_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_objects_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_program_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_programs_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_properties_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_shader_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_shadow_map.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_shadow_map_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/webgl/xwebgl_state_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/xwebgl_render_target_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/xwebgl_render_target_cube_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/renderers/xwebgl_renderer.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/scenes/xfog_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/scenes/xfog_exp2_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/scenes/xscene_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xcompressed_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xcube_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xdata_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xdepth_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/ximage_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xtext_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xtexture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/textures/xvideo_texture_autogen.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xanimation.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xaudio.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xbase.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xcameras.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xcontrols.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xcore.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xextras.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xgeometries.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xhelpers.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xlights.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xloaders.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xmaterials.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xmath.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xobjects.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xrenderers.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xscenes.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xtextures.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs_config.hpp
    ${XTHREEJS_INCLUDE_DIR}/xthreejs/xthreejs_config.hpp
)

OPTION(PRECOMPILED "precompile xthreejs instances" OFF)

if (PRECOMPILED)
    set(XTHREEJS_SOURCES
        ${XTHREEJS_SOURCE_DIR}/animation/tracks/xboolean_keyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/tracks/xcolor_keyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/tracks/xnumber_keyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/tracks/xquaternion_keyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/tracks/xstring_keyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/tracks/xvector_keyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xanimation_action.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xanimation_action_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xanimation_clip_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xanimation_mixer_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xanimation_object_group_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xanimation_utils_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xkeyframe_track_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xproperty_binding_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/animation/xproperty_mixer_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/audio/xaudio_analyser_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/audio/xaudio_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/audio/xaudio_listener_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/audio/xpositional_audio_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/base/xrender.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xarray_camera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xcamera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xcombined_camera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xcube_camera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xorthographic_camera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xperspective_camera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/cameras/xstereo_camera_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/controls/xcontrols_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/controls/xfly_controls_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/controls/xorbit_controls_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/controls/xpicker_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/controls/xtrackball_controls_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xbase_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xbase_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xbuffer_attribute_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xbuffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xclock_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xdirect_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xevent_dispatcher_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xgeometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xinstanced_buffer_attribute_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xinstanced_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xinstanced_interleaved_buffer_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xinterleaved_buffer_attribute_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xinterleaved_buffer_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xlayers_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xobject3d.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xobject3d_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xraycaster_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xrenderer.cpp
        ${XTHREEJS_SOURCE_DIR}/core/xuniform_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/core/xcurve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/core/xcurve_path_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/core/xfont_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/core/xpath_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/core/xshape_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/core/xshape_path_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xarc_curve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xcatmull_rom_curve3_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xcubic_bezier_curve3_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xcubic_bezier_curve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xellipse_curve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xline_curve3_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xline_curve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xquadratic_bezier_curve3_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xquadratic_bezier_curve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/curves/xspline_curve_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/objects/ximmediate_render_object_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/xscene_utils_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/extras/xshape_utils_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xbox_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xbox_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xcircle_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xcircle_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xcone_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xcylinder_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xcylinder_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xdodecahedron_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xedges_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xextrude_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xicosahedron_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xlathe_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xlathe_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xoctahedron_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xparametric_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xplane_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xplane_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xpolyhedron_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xring_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xring_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xshape_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xsphere_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xsphere_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtetrahedron_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtext_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtorus_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtorus_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtorus_knot_buffer_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtorus_knot_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xtube_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/geometries/xwireframe_geometry_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xarrow_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xaxes_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xbox3helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xbox_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xcamera_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xdirectional_light_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xface_normals_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xgrid_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xhemisphere_light_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xplane_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xpoint_light_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xpolar_grid_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xrect_area_light_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xskeleton_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xspot_light_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/helpers/xvertex_normals_helper_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xambient_light_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xdirectional_light_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xdirectional_light_shadow_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xhemisphere_light_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xlight_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xlight_shadow_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xpoint_light_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xrect_area_light_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xspot_light_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/lights/xspot_light_shadow_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xanimation_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xaudio_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xbuffer_geometry_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xcache_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xcompressed_texture_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xcube_texture_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xdata_texture_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xfile_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xfont_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/ximage_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xj_s_o_n_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xloader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xloading_manager_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xmaterial_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xobject_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/loaders/xtexture_loader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xline_basic_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xline_dashed_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmaterial_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_basic_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_depth_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_lambert_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_normal_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_phong_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_physical_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_standard_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xmesh_toon_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xpoints_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xraw_shader_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xshader_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xshadow_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/materials/xsprite_material_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/interpolants/xcubic_interpolant_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/interpolants/xdiscrete_interpolant_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/interpolants/xlinear_interpolant_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/interpolants/xquaternion_linear_interpolant_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xbox2_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xbox3_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xcylindrical_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xfrustum_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xinterpolant_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xline3_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xmath_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xplane_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xquaternion_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xray_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xsphere_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xspherical_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/math/xtriangle_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xblackbox_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xbone_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xclone_array_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xgroup_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xl_o_d_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xlens_flare_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xline_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xline_loop_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xline_segments_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xmesh_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xpoints_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xskeleton_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xskinned_mesh_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/objects/xsprite_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_buffer_renderer_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_capabilities_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_extensions_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_geometries_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_indexed_buffer_renderer_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_lights_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_objects_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_program_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_programs_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_properties_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_shader_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_shadow_map_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/webgl/xwebgl_state_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/xwebgl_render_target_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/renderers/xwebgl_render_target_cube_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/scenes/xfog_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/scenes/xfog_exp2_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/scenes/xscene_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xcompressed_texture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xcube_texture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xdata_texture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xdepth_texture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/ximage_texture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xtext_texture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xtexture_autogen.cpp
        ${XTHREEJS_SOURCE_DIR}/textures/xvideo_texture_autogen.cpp
    )
endif()

# Output
# ======

if (PRECOMPILED)
    add_library(xthreejs SHARED ${XTHREEJS_SOURCES} ${XTHREEJS_HEADERS})
    target_include_directories(xthreejs PUBLIC $<BUILD_INTERFACE:${XTHREEJS_INCLUDE_DIR}>
                                               $<INSTALL_INTERFACE:include>)
else()
    add_library(xthreejs INTERFACE)
    target_include_directories(xthreejs INTERFACE $<BUILD_INTERFACE:${XTHREEJS_INCLUDE_DIR}>
                                               $<INSTALL_INTERFACE:include>)
endif()
    


if (PRECOMPILED)
    target_link_libraries(xthreejs
                    PUBLIC xtl
                    PUBLIC xwidgets
                    PRIVATE xeus)

    set_target_properties(xthreejs PROPERTIES
        PUBLIC_HEADER "${XTHREEJS_HEADERS}"
        COMPILE_DEFINITIONS "XTHREEJS_EXPORTS"
        PREFIX ""
        VERSION ${XTHREEJS_BINARY_VERSION}
        SOVERSION ${XTHREEJS_BINARY_CURRENT}
        OUTPUT_NAME "libxthreejs")
endif()

# Compilation flags
# =================

include(CheckCXXCompilerFlag)
string(TOUPPER "${CMAKE_BUILD_TYPE}" U_CMAKE_BUILD_TYPE)
OPTION(DISABLE_ARCH_NATIVE "disable -march=native flag" OFF)

if (PRECOMPILED)
    set_target_properties(xthreejs PROPERTIES
        CXX_EXTENSIONS OFF
        CXX_STANDARD_REQUIRED 14)
    
    target_compile_features(xthreejs PRIVATE cxx_std_14)


if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    target_compile_options(xthreejs PUBLIC -Wunused-parameter -Wextra -Wreorder)
    if (DISABLE_ARCH_NATIVE)
        target_compile_options(xthreejs PUBLIC -mtune=generic)
    else()
        target_compile_options(xthreejs PUBLIC -march=native)
    endif()

    # Enable link time optimization and set the default symbol
    # visibility to hidden (very important to obtain small binaries)
    if (NOT ${U_CMAKE_BUILD_TYPE} MATCHES DEBUG)
        # Check for Link Time Optimization support
        # (GCC/Clang)
        CHECK_CXX_COMPILER_FLAG("-flto" HAS_LTO_FLAG)
        if (HAS_LTO_FLAG)
            target_compile_options(xthreejs PUBLIC -flto)
        endif()

        # Intel equivalent to LTO is called IPO
        if (CMAKE_CXX_COMPILER_ID MATCHES "Intel")
            CHECK_CXX_COMPILER_FLAG("-ipo" HAS_IPO_FLAG)
            if (HAS_IPO_FLAG)
                target_compile_options(xthreejs PUBLIC -ipo)
            endif()
        endif()
    endif()
    message(STATUS "CMAKE_CXX_FLAGS: ${CMAKE_CXX_FLAGS}")
endif()
endif()

# Installation
# ============

set(XTHREEJS_CMAKECONFIG_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}" CACHE STRING "install path for xthreejsConfig.cmake")

install(DIRECTORY ${XTHREEJS_INCLUDE_DIR}/xthreejs DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(TARGETS xthreejs
        EXPORT ${PROJECT_NAME}-targets
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})

# Makes the project importable from the build directory
export(EXPORT ${PROJECT_NAME}-targets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Targets.cmake")

configure_package_config_file(${PROJECT_NAME}Config.cmake.in
                              "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
                              INSTALL_DESTINATION ${XTHREEJS_CMAKECONFIG_INSTALL_DIR})
write_basic_package_version_file(${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
                                 VERSION ${XTHREEJS_VERSION}
                                 COMPATIBILITY AnyNewerVersion)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
              ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
              DESTINATION ${XTHREEJS_CMAKECONFIG_INSTALL_DIR})
install(EXPORT ${PROJECT_NAME}-targets
        FILE ${PROJECT_NAME}Targets.cmake
DESTINATION ${XTHREEJS_CMAKECONFIG_INSTALL_DIR})