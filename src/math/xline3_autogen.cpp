#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline3>;
template xw::xmaterialize<xthree::xline3>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline3>>;
template class xw::xgenerator<xthree::xline3>;
template xw::xgenerator<xthree::xline3>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline3>>;