#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xdirectional_light>;
template xw::xmaterialize<xthree::xdirectional_light>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xdirectional_light>>;
template class xw::xgenerator<xthree::xdirectional_light>;
template xw::xgenerator<xthree::xdirectional_light>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xdirectional_light>>;