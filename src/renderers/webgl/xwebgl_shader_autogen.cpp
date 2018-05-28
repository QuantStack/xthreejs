#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_shader>;
template xw::xmaterialize<xthree::xwebgl_shader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_shader>>;
template class xw::xgenerator<xthree::xwebgl_shader>;
template xw::xgenerator<xthree::xwebgl_shader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_shader>>;