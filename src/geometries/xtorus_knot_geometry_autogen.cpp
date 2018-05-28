#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtorus_knot_geometry>;
template xw::xmaterialize<xthree::xtorus_knot_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtorus_knot_geometry>>;
template class xw::xgenerator<xthree::xtorus_knot_geometry>;
template xw::xgenerator<xthree::xtorus_knot_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtorus_knot_geometry>>;