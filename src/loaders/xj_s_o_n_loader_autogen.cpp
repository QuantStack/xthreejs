#include "xthreejs/xthreejs.hpp"

template class xw::xmaterialize<xthree::xj_s_o_n_loader>;
template xw::xmaterialize<xthree::xj_s_o_n_loader>::xmaterialize();
template class xw::xtransport<xw::xmaterialize<xthree::xj_s_o_n_loader>>;
template class xw::xgenerator<xthree::xj_s_o_n_loader>;
template xw::xgenerator<xthree::xj_s_o_n_loader>::xgenerator();
template class xw::xtransport<xw::xgenerator<xthree::xj_s_o_n_loader>>;