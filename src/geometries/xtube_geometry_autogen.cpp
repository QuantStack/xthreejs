#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xtube_geometry>;
template xw::xmaterialize<xthree::xtube_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xtube_geometry>>;
template class xw::xgenerator<xthree::xtube_geometry>;
template xw::xgenerator<xthree::xtube_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xtube_geometry>>;