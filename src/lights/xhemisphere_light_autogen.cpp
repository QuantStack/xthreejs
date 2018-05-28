#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xhemisphere_light>;
template xw::xmaterialize<xthree::xhemisphere_light>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xhemisphere_light>>;
template class xw::xgenerator<xthree::xhemisphere_light>;
template xw::xgenerator<xthree::xhemisphere_light>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xhemisphere_light>>;