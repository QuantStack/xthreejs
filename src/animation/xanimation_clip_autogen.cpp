#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_clip>;
template xw::xmaterialize<xthree::xanimation_clip>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_clip>>;
template class xw::xgenerator<xthree::xanimation_clip>;
template xw::xgenerator<xthree::xanimation_clip>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_clip>>;