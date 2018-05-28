#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xarc_curve>;
template xw::xmaterialize<xthree::xarc_curve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xarc_curve>>;
template class xw::xgenerator<xthree::xarc_curve>;
template xw::xgenerator<xthree::xarc_curve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xarc_curve>>;