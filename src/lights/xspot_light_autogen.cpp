#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xspot_light>;
template xw::xmaterialize<xthree::xspot_light>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xspot_light>>;
template class xw::xgenerator<xthree::xspot_light>;
template xw::xgenerator<xthree::xspot_light>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xspot_light>>;