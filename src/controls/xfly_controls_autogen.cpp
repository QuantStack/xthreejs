#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfly_controls>;
template xw::xmaterialize<xthree::xfly_controls>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfly_controls>>;
template class xw::xgenerator<xthree::xfly_controls>;
template xw::xgenerator<xthree::xfly_controls>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfly_controls>>;