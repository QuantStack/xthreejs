#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xwebgl_geometries>;
template xw::xmaterialize<xthree::xwebgl_geometries>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xwebgl_geometries>>;
template class xw::xgenerator<xthree::xwebgl_geometries>;
template xw::xgenerator<xthree::xwebgl_geometries>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xwebgl_geometries>>;