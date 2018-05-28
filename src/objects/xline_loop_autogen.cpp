#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline_loop>;
template xw::xmaterialize<xthree::xline_loop>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline_loop>>;
template class xw::xgenerator<xthree::xline_loop>;
template xw::xgenerator<xthree::xline_loop>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline_loop>>;