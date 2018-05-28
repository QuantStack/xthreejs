#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xicosahedron_geometry>;
template xw::xmaterialize<xthree::xicosahedron_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xicosahedron_geometry>>;
template class xw::xgenerator<xthree::xicosahedron_geometry>;
template xw::xgenerator<xthree::xicosahedron_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xicosahedron_geometry>>;