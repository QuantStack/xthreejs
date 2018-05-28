#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_render_target>;
template xw::xmaterialize<xthree::xwebgl_render_target>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_render_target>>;
template class xw::xgenerator<xthree::xwebgl_render_target>;
template xw::xgenerator<xthree::xwebgl_render_target>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_render_target>>;