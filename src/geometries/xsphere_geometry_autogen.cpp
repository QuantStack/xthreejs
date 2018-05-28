#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xsphere_geometry>;
template xw::xmaterialize<xthree::xsphere_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xsphere_geometry>>;
template class xw::xgenerator<xthree::xsphere_geometry>;
template xw::xgenerator<xthree::xsphere_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xsphere_geometry>>;