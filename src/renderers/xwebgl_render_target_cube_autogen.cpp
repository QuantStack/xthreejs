#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_render_target_cube>;
template xw::xmaterialize<xthree::xwebgl_render_target_cube>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_render_target_cube>>;
template class xw::xgenerator<xthree::xwebgl_render_target_cube>;
template xw::xgenerator<xthree::xwebgl_render_target_cube>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_render_target_cube>>;