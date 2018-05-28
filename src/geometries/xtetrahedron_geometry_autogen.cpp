#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtetrahedron_geometry>;
template xw::xmaterialize<xthree::xtetrahedron_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtetrahedron_geometry>>;
template class xw::xgenerator<xthree::xtetrahedron_geometry>;
template xw::xgenerator<xthree::xtetrahedron_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtetrahedron_geometry>>;