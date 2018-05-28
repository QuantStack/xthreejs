#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xpoint_light_helper>;
template xw::xmaterialize<xthree::xpoint_light_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xpoint_light_helper>>;
template class xw::xgenerator<xthree::xpoint_light_helper>;
template xw::xgenerator<xthree::xpoint_light_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xpoint_light_helper>>;