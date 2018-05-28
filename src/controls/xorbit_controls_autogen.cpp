#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xorbit_controls>;
template xw::xmaterialize<xthree::xorbit_controls>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xorbit_controls>>;
template class xw::xgenerator<xthree::xorbit_controls>;
template xw::xgenerator<xthree::xorbit_controls>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xorbit_controls>>;