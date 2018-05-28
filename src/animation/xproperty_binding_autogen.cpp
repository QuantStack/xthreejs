#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xproperty_binding>;
template xw::xmaterialize<xthree::xproperty_binding>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xproperty_binding>>;
template class xw::xgenerator<xthree::xproperty_binding>;
template xw::xgenerator<xthree::xproperty_binding>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xproperty_binding>>;