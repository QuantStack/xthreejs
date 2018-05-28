#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xellipse_curve>;
template xw::xmaterialize<xthree::xellipse_curve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xellipse_curve>>;
template class xw::xgenerator<xthree::xellipse_curve>;
template xw::xgenerator<xthree::xellipse_curve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xellipse_curve>>;