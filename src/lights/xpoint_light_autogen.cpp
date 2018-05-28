#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpoint_light>;
template xw::xmaterialize<xthree::xpoint_light>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpoint_light>>;
template class xw::xgenerator<xthree::xpoint_light>;
template xw::xgenerator<xthree::xpoint_light>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpoint_light>>;