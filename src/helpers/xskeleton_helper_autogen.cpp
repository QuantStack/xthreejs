#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xskeleton_helper>;
template xw::xmaterialize<xthree::xskeleton_helper>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xskeleton_helper>>;
template class xw::xgenerator<xthree::xskeleton_helper>;
template xw::xgenerator<xthree::xskeleton_helper>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xskeleton_helper>>;