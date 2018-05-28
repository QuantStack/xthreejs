#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xskeleton>;
template xw::xmaterialize<xthree::xskeleton>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xskeleton>>;
template class xw::xgenerator<xthree::xskeleton>;
template xw::xgenerator<xthree::xskeleton>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xskeleton>>;