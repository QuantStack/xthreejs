#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xfog_exp2>;
template xw::xmaterialize<xthree::xfog_exp2>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xfog_exp2>>;
template class xw::xgenerator<xthree::xfog_exp2>;
template xw::xgenerator<xthree::xfog_exp2>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xfog_exp2>>;