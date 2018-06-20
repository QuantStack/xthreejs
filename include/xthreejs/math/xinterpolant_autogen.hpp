#ifndef XTHREE_INTERPOLANT_HPP
#define XTHREE_INTERPOLANT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // interpolant declaration
    //

    template<class D>
    class xinterpolant : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xinterpolant();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using interpolant = xw::xmaterialize<xinterpolant>;

    using interpolant_generator = xw::xgenerator<xinterpolant>;

    //
    // interpolant implementation
    //


    template <class D>
    inline void xinterpolant<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xinterpolant<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xinterpolant<D>::xinterpolant()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xinterpolant<D>::set_defaults()
    {
        this->_model_name() = "InterpolantModel";
        this->_view_name() = "";
    }
}

xeus::xjson mime_bundle_repr(xw::xmaterialize<xthree::xinterpolant>& widget);

/*********************
 * precompiled types *
 *********************/

#ifdef XTHREEJS_PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xinterpolant>;
        extern template xw::xmaterialize<xthree::xinterpolant>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xinterpolant>>;
        extern template class xw::xgenerator<xthree::xinterpolant>;
        extern template xw::xgenerator<xthree::xinterpolant>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xinterpolant>>;
    #endif
#endif

#endif