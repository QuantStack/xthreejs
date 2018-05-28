#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xanimation_utils>;
template xw::xmaterialize<xthree::xanimation_utils>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xanimation_utils>>;
template class xw::xgenerator<xthree::xanimation_utils>;
template xw::xgenerator<xthree::xanimation_utils>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xanimation_utils>>;