#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xscene_utils>;
template xw::xmaterialize<xthree::xscene_utils>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xscene_utils>>;
template class xw::xgenerator<xthree::xscene_utils>;
template xw::xgenerator<xthree::xscene_utils>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xscene_utils>>;