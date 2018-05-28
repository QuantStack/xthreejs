#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xambient_light>;
template xw::xmaterialize<xthree::xambient_light>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xambient_light>>;
template class xw::xgenerator<xthree::xambient_light>;
template xw::xgenerator<xthree::xambient_light>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xambient_light>>;