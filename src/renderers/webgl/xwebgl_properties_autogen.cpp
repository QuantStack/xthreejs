#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_properties>;
template xw::xmaterialize<xthree::xwebgl_properties>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_properties>>;
template class xw::xgenerator<xthree::xwebgl_properties>;
template xw::xgenerator<xthree::xwebgl_properties>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_properties>>;