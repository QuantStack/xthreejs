#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xparametric_geometry>;
template xw::xmaterialize<xthree::xparametric_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xparametric_geometry>>;
template class xw::xgenerator<xthree::xparametric_geometry>;
template xw::xgenerator<xthree::xparametric_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xparametric_geometry>>;