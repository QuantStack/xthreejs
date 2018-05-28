#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xrect_area_light>;
template xw::xmaterialize<xthree::xrect_area_light>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xrect_area_light>>;
template class xw::xgenerator<xthree::xrect_area_light>;
template xw::xgenerator<xthree::xrect_area_light>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xrect_area_light>>;