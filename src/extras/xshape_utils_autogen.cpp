#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xshape_utils>;
template xw::xmaterialize<xthree::xshape_utils>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xshape_utils>>;
template class xw::xgenerator<xthree::xshape_utils>;
template xw::xgenerator<xthree::xshape_utils>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xshape_utils>>;