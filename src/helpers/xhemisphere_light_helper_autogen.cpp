#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xhemisphere_light_helper>;
template xw::xmaterialize<xthree::xhemisphere_light_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xhemisphere_light_helper>>;
template class xw::xgenerator<xthree::xhemisphere_light_helper>;
template xw::xgenerator<xthree::xhemisphere_light_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xhemisphere_light_helper>>;