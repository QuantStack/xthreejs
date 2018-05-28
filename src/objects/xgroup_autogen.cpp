#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xgroup>;
template xw::xmaterialize<xthree::xgroup>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xgroup>>;
template class xw::xgenerator<xthree::xgroup>;
template xw::xgenerator<xthree::xgroup>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xgroup>>;