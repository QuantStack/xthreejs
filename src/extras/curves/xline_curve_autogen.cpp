#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline_curve>;
template xw::xmaterialize<xthree::xline_curve>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline_curve>>;
template class xw::xgenerator<xthree::xline_curve>;
template xw::xgenerator<xthree::xline_curve>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline_curve>>;