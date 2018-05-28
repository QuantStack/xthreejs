#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xloading_manager>;
template xw::xmaterialize<xthree::xloading_manager>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xloading_manager>>;
template class xw::xgenerator<xthree::xloading_manager>;
template xw::xgenerator<xthree::xloading_manager>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xloading_manager>>;