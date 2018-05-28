#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xspot_light_shadow>;
template xw::xmaterialize<xthree::xspot_light_shadow>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xspot_light_shadow>>;
template class xw::xgenerator<xthree::xspot_light_shadow>;
template xw::xgenerator<xthree::xspot_light_shadow>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xspot_light_shadow>>;