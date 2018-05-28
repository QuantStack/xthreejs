#ifndef XTHREE_LINEAR_INTERPOLANT_HPP
#define XTHREE_LINEAR_INTERPOLANT_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // linear_interpolant declaration
    //

    template<class D>
    class xlinear_interpolant : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xlinear_interpolant();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using linear_interpolant = xw::xmaterialize<xlinear_interpolant>;

    using linear_interpolant_generator = xw::xgenerator<xlinear_interpolant>;

    //
    // linear_interpolant implementation
    //


    template <class D>
    inline void xlinear_interpolant<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xlinear_interpolant<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xlinear_interpolant<D>::xlinear_interpolant()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xlinear_interpolant<D>::set_defaults()
    {
        this->_model_name() = "LinearInterpolantModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xlinear_interpolant>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xlinear_interpolant>;
        extern template xw::xmaterialize<xthree::xlinear_interpolant>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xlinear_interpolant>>;
        extern template class xw::xgenerator<xthree::xlinear_interpolant>;
        extern template xw::xgenerator<xthree::xlinear_interpolant>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xlinear_interpolant>>;
    #endif
#endif

#endif