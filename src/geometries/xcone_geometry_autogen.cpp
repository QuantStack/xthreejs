#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xcone_geometry>;
template xw::xmaterialize<xthree::xcone_geometry>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xcone_geometry>>;
template class xw::xgenerator<xthree::xcone_geometry>;
template xw::xgenerator<xthree::xcone_geometry>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xcone_geometry>>;