#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xl_o_d>;
template xw::xmaterialize<xthree::xl_o_d>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xl_o_d>>;
template class xw::xgenerator<xthree::xl_o_d>;
template xw::xgenerator<xthree::xl_o_d>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xl_o_d>>;