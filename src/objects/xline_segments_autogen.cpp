#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xline_segments>;
template xw::xmaterialize<xthree::xline_segments>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xline_segments>>;
template class xw::xgenerator<xthree::xline_segments>;
template xw::xgenerator<xthree::xline_segments>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xline_segments>>;