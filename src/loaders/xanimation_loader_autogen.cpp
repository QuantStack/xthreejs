#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_loader>;
template xw::xmaterialize<xthree::xanimation_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_loader>>;
template class xw::xgenerator<xthree::xanimation_loader>;
template xw::xgenerator<xthree::xanimation_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_loader>>;