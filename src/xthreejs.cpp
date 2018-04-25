// #include "xthreejs/xthreejs.hpp"

// namespace xw
// {
//     XPRECOMPILE(NO_EXTERN, (xthree::xanimation_action ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xanimation_clip ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xanimation_mixer ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xanimation_object_group ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xanimation_utils ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xkeyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xproperty_binding ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xproperty_mixer ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xaudio_analyser ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xaudio ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xaudio_listener ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpositional_audio ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xarray_camera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcamera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcombined_camera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcube_camera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xorthographic_camera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xperspective_camera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xstereo_camera ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcontrols ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfly_controls ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xorbit_controls ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpicker ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtrackball_controls ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbase_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbase_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbuffer_attribute ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbuffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xclock ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdirect_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xevent_dispatcher ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xgeometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xinstanced_buffer_attribute ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xinstanced_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xinstanced_interleaved_buffer ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xinterleaved_buffer_attribute ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xinterleaved_buffer ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlayers ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xobject3d ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xraycaster ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xuniform ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xscene_utils ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xshape_utils ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbox_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbox_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcircle_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcircle_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcone_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcylinder_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcylinder_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdodecahedron_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xedges_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xextrude_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xicosahedron_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlathe_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlathe_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xoctahedron_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xparametric_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xplane_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xplane_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpolyhedron_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xring_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xring_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xshape_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xsphere_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xsphere_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtetrahedron_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtext_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtorus_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtorus_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtorus_knot_buffer_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtorus_knot_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtube_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwireframe_geometry ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xarrow_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xaxes_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbox3helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbox_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcamera_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdirectional_light_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xface_normals_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xgrid_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xhemisphere_light_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xplane_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpoint_light_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpolar_grid_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xrect_area_light_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xskeleton_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xspot_light_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xvertex_normals_helper ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xambient_light ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdirectional_light ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdirectional_light_shadow ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xhemisphere_light ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlight ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlight_shadow ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpoint_light ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xrect_area_light ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xspot_light ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xspot_light_shadow ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xanimation_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xaudio_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbuffer_geometry_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcache ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcompressed_texture_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcube_texture_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdata_texture_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfile_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfont_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::ximage_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xj_s_o_n_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xloader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xloading_manager ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmaterial_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xobject_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtexture_loader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline_basic_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline_dashed_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmaterial ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_basic_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_depth_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_lambert_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_normal_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_phong_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_physical_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_standard_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh_toon_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpoints_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xraw_shader_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xshader_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xshadow_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xsprite_material ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbox2 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbox3 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcylindrical ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xinterpolant ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfrustum ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline3 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmath ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xplane ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xquaternion ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xray ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xsphere ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xspherical ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtriangle ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xblackbox ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xbone ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xclone_array ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xgroup ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xl_o_d ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlens_flare ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline_loop ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline_segments ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xmesh ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpoints ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xskeleton ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xskinned_mesh ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xsprite ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_render_target ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_render_target_cube ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfog ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfog_exp2 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xscene ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcompressed_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcube_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdata_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdepth_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::ximage_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtext_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xtexture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xvideo_texture ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xboolean_keyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcolor_keyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xnumber_keyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xquaternion_keyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xstring_keyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xvector_keyframe_track ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcurve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcurve_path ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xfont ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xpath ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xshape ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xshape_path ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xarc_curve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcatmull_rom_curve3 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcubic_bezier_curve3 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcubic_bezier_curve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xellipse_curve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline_curve3 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xline_curve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xquadratic_bezier_curve3 ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xquadratic_bezier_curve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xspline_curve ));
//     XPRECOMPILE(NO_EXTERN, (xthree::ximmediate_render_object ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xcubic_interpolant ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xdiscrete_interpolant ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xlinear_interpolant ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xquaternion_linear_interpolant ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_buffer_renderer ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_capabilities ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_extensions ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_geometries ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_indexed_buffer_renderer ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_lights ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_objects ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_program ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_programs ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_properties ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_shader ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_shadow_map ));
//     XPRECOMPILE(NO_EXTERN, (xthree::xwebgl_state ));

//     XPRECOMPILE_WITH_ARG1(EXTERN, (xthree::xpreview),
//         (
//             xthree::box_buffer_geometry,
//             xthree::box_geometry,
//             xthree::circle_buffer_geometry,
//             xthree::circle_geometry,
//             xthree::cone_geometry,
//             xthree::cylinder_buffer_geometry,
//             xthree::cylinder_geometry,
//             xthree::dodecahedron_geometry,
//             xthree::edges_geometry,
//             xthree::extrude_geometry,
//             xthree::icosahedron_geometry,
//             xthree::lathe_buffer_geometry,
//             xthree::lathe_geometry,
//             xthree::octahedron_geometry,
//             xthree::parametric_geometry,
//             xthree::plane_buffer_geometry,
//             xthree::plane_geometry,
//             xthree::polyhedron_geometry,
//             xthree::ring_buffer_geometry,
//             xthree::ring_geometry,
//             xthree::shape_geometry,
//             xthree::sphere_buffer_geometry,
//             xthree::sphere_geometry,
//             xthree::tetrahedron_geometry,
//             xthree::text_geometry,
//             xthree::torus_buffer_geometry,
//             xthree::torus_geometry,
//             xthree::torus_knot_buffer_geometry,
//             xthree::torus_knot_geometry,
//             xthree::tube_geometry,
//             xthree::wireframe_geometry
//         )
//     )
// }