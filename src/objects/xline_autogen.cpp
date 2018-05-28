#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline>;
template xw::xmaterialize<xthree::xline>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline>>;
template class xw::xgenerator<xthree::xline>;
template xw::xgenerator<xthree::xline>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline>>;